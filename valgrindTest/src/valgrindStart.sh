#!/bin/bash
/usr/bin/valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file=valgrind.log ./valgrindTest
