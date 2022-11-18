#!/bin/sh
echo "---Changind permissions---"
chmod 000 dir/no_permission dir/outfile_forbidden.replace
echo "---Normal---"
./sed_2.0 dir/infile i o
echo "---First string empty---"
./sed_2.0 dir/infile2 "" o
echo "---Second string empty---"
./sed_2.0 dir/infile3 i ""
echo "---Too many arguments---"
./sed_2.0 dir/infile i o o
echo "---Too few arguments---"
./sed_2.0 dir/infile i
echo "---Empty file---"
./sed_2.0 dir/empty i o
echo "---Forbidden file---"
./sed_2.0 dir/no_permission i o
echo "---Dir as infile---"
./sed_2.0 dir i o
echo "---Infile doesn't exist---"
./sed_2.0 not_here i o
echo "---Outfile exists and is forbidden---"
./sed_2.0 dir/outfile_forbidden i o
