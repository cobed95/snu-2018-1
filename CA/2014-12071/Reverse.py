stack = []

#Phase 1
rsp -= 1
esi = 402650
#String Not Equal
rsp -= 1
stack[rsp] = r12
rsp -= 1
stack[rsp] = rbp
rsp -= 1
stack[rsp] = rbx
rbx = rdi
rbp = rsi
#String Length
if (*rdi == None):
    return 0
else:
    rdx = rdi
    rdx += 1
    eax = edx
    eax -= edi
    if !(*rdx == None):
        goto (rdx += 1)
    return

