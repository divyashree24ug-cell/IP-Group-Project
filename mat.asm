default rel

section .text
    global addEdge
    global displayMatrix

    extern adj      ; int adj[Max][Max] (from C)
    extern n        ; int n             (from C)
    extern printf


; ------------------------------------------------------
; void addEdge(int u, int v, int directed)
; rdi = u
; rsi = v
; rdx = directed
; ------------------------------------------------------
addEdge:

    ; index = u * n + v
    mov eax, edi            ; eax = u
    mov ecx, [n]            ; ecx = n
    imul eax, ecx           ; eax = u * n
    add eax, esi            ; eax = u*n + v

    ; adj[u][v] = 1
    mov dword [adj + rax*4], 1

    ; if directed != 0 → return
    test edx, edx
    jnz done_add

    ; Now handle undirected graph: adj[v][u] = 1
    mov eax, esi            ; eax = v
    mov ecx, [n]
    imul eax, ecx
    add eax, edi            ; eax = v*n + u
    mov dword [adj + rax*4], 1

done_add:
    ret


; ------------------------------------------------------
; void displayMatrix()
; prints adjacency matrix
; ------------------------------------------------------
displayMatrix:

    ; print header text
    mov rdi, header
    xor eax, eax
    call printf

    ; i = 0
    xor r8d, r8d            ; r8d = i
    mov r9d, [n]            ; r9d = n

outer_loop:
    cmp r8d, r9d
    jge end_display

    ; j = 0
    xor r10d, r10d          ; r10d = j

inner_loop:
    cmp r10d, r9d
    jge print_newline

    ; index = i * n + j
    mov eax, r8d
    imul eax, r9d
    add eax, r10d

    ; print adj[i][j]
    mov esi, dword [adj + rax*4]
    mov rdi, number_fmt
    xor eax, eax
    call printf

    inc r10d
    jmp inner_loop

print_newline:
    mov rdi, newline
    xor eax, eax
    call printf

    inc r8d
    jmp outer_loop

end_display:
    ret


section .data
    header      db "Adjacency Matrix:", 10, 0
    number_fmt  db "%d ", 0
    newline     db 10, 0


