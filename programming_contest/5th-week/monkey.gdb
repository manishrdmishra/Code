# http://sourceware.org/gdb/wiki/FAQ: to disable the
# "---Type <return> to continue, or q <return> to quit---"
# in batch mode:
set width 0
set height 0
set verbose off

# at entry point - cmd1
#b main
b SuffixArray::buildSA
r < 2input
commands 1
watch suf
watch pos
continue
end

# printf line - cmd2
#b test.c:17
#commands 2
#p i
