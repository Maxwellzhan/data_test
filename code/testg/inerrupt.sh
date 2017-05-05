#!/bin/sh

trap 'rm -rf /tmp/my_tmp_file_$$' INT
echo 'creating file /tmp/my_tmp_file_$$'
date > /tmp/my_tmp_file_$$

echo "press interrupt (CRT-C) to interrupt ..."
while [ -f /tmp/my_tmp_file_$$ ]; do
		echo File exists
		sleep 1
done
echo "The file no longer exists"

trap INT
echo creating file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "press interrupt (CTR-C) to interrupt"
while [ -f /tmp/my_tmp_file_$$ ]; do
		echo File exists
		sleep 1
done

echo we never get here
exit 0
