#!/usr/bin/python3
""" Reddit hot article word count """
import requests


def count_words(subreddit, word_list, after='', words_counting={}):
    """ count_words fn """

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'custom'}
    payload = {'limit': '100', 'after': after}
    response = requests.get(url, headers=headers,
                            params=payload, allow_redirects=False)

    if not response.status_code == 200:
        return
    data = response.json().get('data')
    after = data.get('after')
    children_list = data.get('children')

    for child in children_list:
        title = child.get('data').get('title')
        for word in word_list:
            occur = title.lower().split().count(word.lower())
            if occur > 0:
                if word in words_counting:
                    words_counting[word] += occur
                else:
                    words_counting[word] = occur

    if after is not None:
        return count_words(subreddit, word_list, after, words_counting)
    else:
        if not len(words_counting) > 0:
            return
        i = sorted(words_counting.items(),
                          key=lambda kv: (-kv[1], kv[0]))
        for key, value in i:
            print('{}: {}'.format(key.lower(), value))
