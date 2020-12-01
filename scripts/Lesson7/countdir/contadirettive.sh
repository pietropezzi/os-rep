#!/bin/bash

for NAME in `find /usr/include/ -type f -name "*.h"` ; do grep '#' ${NAME} ; done | sort | wc -l
