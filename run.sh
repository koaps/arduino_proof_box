#!/bin/bash

ino build
if [ $? == 0 ]; then
  ino upload
fi
