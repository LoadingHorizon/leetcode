#!/usr/bin/env bash

for word in `cat words.txt`; do echo $word; done | sort | uniq -c | sort -k1nr | awk '{print $2, $1}'
