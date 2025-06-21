section .data
    hello db 'Hello, World!', 0
    helloLen equ $ - hello - 1  ; Length of the string without the null terminator
    written  dd 0               ; Variable to store the number of characters written

section .text
    global _start
    extern _GetStdHandle@4, _WriteConsoleA@20, _ExitProcess@4

_start:
    ; Get the handle for standard output
    push -11                     ; STD_OUTPUT_HANDLE
    call _GetStdHandle@4         ; Call GetStdHandle
    ; EAX now contains the handle

    ; Write the string to the console
    push 0                       ; Reserved, must be NULL
    push written                 ; Pointer to the number of characters written
    push helloLen                ; Number of characters to write
    push hello                   ; Pointer to the string to write
    push eax                     ; Handle to the console
    call _WriteConsoleA@20       ; Call WriteConsoleA

    ; Exit the process
    push 0                       ; Exit code
    call _ExitProcess@4          ; Call ExitProcess
