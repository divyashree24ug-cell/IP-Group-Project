global BFS
extern n
extern adj
extern printf

section .data
    bfs_msg db "BFS Traversal: ", 0  ; Message string for BFS output
    fmt db "%d ", 0                  ; Format string for printing numbers

section .text

; void BFS(int start)
; Input: start vertex in EDI register (System V AMD64 calling convention)
BFS:
    push rbp                ; Save old base pointer
    mov rbp, rsp            ; Set new base pointer
    sub rsp, 88             ; Allocate stack space: visited[10](40) + queue[10](40) + front(4) + rear(4)
    
    ; Stack frame layout:
    ; rbp-40 to rbp-1: visited[10] (40 bytes)
    ; rbp-80 to rbp-41: queue[10] (40 bytes)  
    ; rbp-84: front (4 bytes)
    ; rbp-88: rear (4 bytes)
    
    mov esi, edi            ; Save start parameter from EDI to ESI
    
    ; Initialize visited array to all zeros
    lea r8, [rbp-40]        ; R8 = address of visited array (base pointer - 40)
    xor eax, eax            ; EAX = 0 (counter and value)
    mov ecx, 10             ; ECX = 10 (Max size)
.init_visited:
    mov dword [r8 + rax*4], 0  ; visited[i] = 0
    inc eax                 ; i++
    cmp eax, 10             ; Check if i < 10
    jl .init_visited        ; Continue loop if i < 10
    
    ; Initialize queue pointers
    mov dword [rbp-84], 0   ; front = 0
    mov dword [rbp-88], 0   ; rear = 0
    
    ; Print BFS message
    mov rdi, bfs_msg        ; First argument: address of message string
    xor eax, eax            ; 0 floating point arguments (System V ABI)
    call printf             ; Call printf function
    
    ; Mark start node as visited
    mov dword [r8 + rsi*4], 1  ; visited[start] = 1
    
    ; Add start node to queue
    mov eax, [rbp-88]       ; EAX = rear
    lea r9, [rbp-80]        ; R9 = address of queue array
    mov [r9 + rax*4], esi   ; queue[rear] = start
    inc eax                 ; rear++
    mov [rbp-88], eax       ; Store updated rear value

; ================= MAIN BFS LOOP =================
.bfs_while:
    ; Check if queue is empty (front >= rear)
    mov eax, [rbp-84]       ; EAX = front
    mov ebx, [rbp-88]       ; EBX = rear
    cmp eax, ebx            ; Compare front and rear
    jge .done               ; If front >= rear, queue is empty -> done
    
    ; Dequeue next node
    mov ecx, [r9 + rax*4]   ; ECX = node = queue[front]
    inc eax                 ; front++
    mov [rbp-84], eax       ; Store updated front value
    
    ; Print the current node
    mov rdi, fmt            ; First argument: format string "%d "
    mov esi, ecx            ; Second argument: node value to print
    xor eax, eax            ; 0 floating point arguments
    call printf             ; Call printf
    
    ; ============ CHECK ALL NEIGHBORS ============
    xor edi, edi            ; EDI = i = 0 (loop counter)
.for_loop:
    cmp edi, [n]            ; Compare i with n (graph size)
    jge .bfs_while          ; If i >= n, go to next BFS iteration
    
    ; Check if there's an edge from node to i
    ; Calculate adj[node][i] address: adj + (node * n + i) * 4
    mov eax, [n]            ; EAX = n
    imul eax, ecx           ; EAX = node * n
    add eax, edi            ; EAX = node * n + i
    mov r10, [adj]          ; R10 = base address of adj matrix
    cmp dword [r10 + rax*4], 1  ; Compare adj[node][i] with 1
    jne .next               ; If no edge, skip to next neighbor
    
    ; Check if neighbor i is already visited
    cmp dword [r8 + rdi*4], 0  ; Compare visited[i] with 0
    jne .next               ; If already visited, skip
    
    ; Mark neighbor as visited and enqueue it
    mov dword [r8 + rdi*4], 1  ; visited[i] = 1
    
    ; Enqueue the neighbor
    mov eax, [rbp-88]       ; EAX = rear
    mov [r9 + rax*4], edi   ; queue[rear] = i
    inc eax                 ; rear++
    mov [rbp-88], eax       ; Store updated rear value

.next:
    inc edi                 ; i++
    jmp .for_loop           ; Continue neighbor loop

.done:
    mov rsp, rbp            ; Restore stack pointer
    pop rbp                 ; Restore base pointer
    ret                     ; Return from function
