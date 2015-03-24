#!/usr/bin/env bash

for i in `cat words.txt`; do echo $i; done | sort | uniq -c | sort -k1nr | awk '{print $2, $1}'
