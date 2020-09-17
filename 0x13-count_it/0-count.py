#!/usr/bin/python3
"""
0x13. Count it!
"""

import requests
import sys


def count_words(subreddit, word_list, kw_cont={}, next_pg=None, reap_kw={}):
    """all hot posts by keyword"""
    headers = {"User-Agent": "Diegokernel"}

    if next_pg:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next_pg, headers=headers)
    else:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json', headers=headers)

    if subr.status_code == 404:
        return

    if kw_cont == {}:
        for word in word_list:
            kw_cont[word] = 0
            reap_kw[word] = word_list.count(word)

    sudi = subr.json()
    suda = sudi['data']
    nxt = suda['after']
    supo = suda['children']

    for post in supo:
        posda = post['data']
        posti = posda['title']
        title = posti.split()
        for w in title:
            for key in kw_cont:
                if w.lower() == key.lower():
                    kw_cont[key] += 1

    if nxt:
        count_words(subreddit, word_list, kw_cont, nxt, reap_kw)

    else:
        for key, val in reap_kw.items():
            if val > 1:
                kw_cont[key] *= val

        sora = sorted(kw_cont.items(), key=lambda x: x[0])
        sores = sorted(sora, key=lambda x: (-x[1], x[0]))
        for res in sores:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
