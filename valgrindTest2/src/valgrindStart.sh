#!/bin/bash
/usr/bin/valgrind --track-fds=yes -v --tool=memcheck --leak-check=full  --show-reachable=yes --track-origins=yes --log-file=valgrind.log ./valgrindTest
