#!/bin/bash

DEVICE=/dev/ttyUSB0

docker run -it --device=$DEVICE -v ${PWD}/src:/app/src:ro arduino_proof_box
