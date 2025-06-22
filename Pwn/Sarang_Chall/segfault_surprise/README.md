# Segfault Surprise

## Challenge Description

The system crashes on bad input — but instead of failing, it reveals a secret. Can you break it just right?

**MD5 Hash**: 1be5bd05a227b13d21305ef4f364c36e

## Short Writeup

A buffer overflow causes a segmentation fault, triggering a signal handler that prints the flag. Overflow the input to cause the segfault and get the flag.

## Flag

bi0s{57ack_5m44444sh}

## Author

**Hellothere**