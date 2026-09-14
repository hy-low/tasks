global calc_area
global is_odd
global range_sum
global squared_sum
global analyze_rectangle
global count_steps
global digit_count
global array_even_count
global array_min_value
global array_is_sorted
global convert_array
global array_distinct_count
global count_letters
global count_words
global is_palindrome
global check_anagrams
global valid_student_number

section .text
calc_area:
    mov rax, rdi
    mul rsi
    ret

is_odd:
    mov rax, rdi
    and rax, 1
    ret

range_sum:
    mov rax, 0
rs_loop:
    add rax, rdi
    dec rdi
    cmp rdi, 0
    jne rs_loop
    ret

squared_sum:
    mov rcx, 0
ss_loop:
    mov rax, rdi
    mul rdi
    add rcx, rax
    dec rdi
    cmp rdi, 0
    jne ss_loop
    mov rax, rcx
    ret

analyze_rectangle:
    mov rax, rdi
    push rdx
    mul rsi
    pop rdx
    mov [rdx], rax
    mov rax, rdi
    add rax, rsi
    shl rax, 1
    mov [rcx], rax
    ret

count_steps:
    mov rax, 0
cs_loop:
    cmp rdi, 0
    je cs_end
    inc rax
    mov rcx, rdi
    and rcx, 1
    cmp rcx, 1
    je cs_dec
    shr rdi, 1
    jmp cs_loop
cs_dec:
    dec rdi
    jmp cs_loop
cs_end:
    ret

digit_count:
    mov rcx, 0
    mov rax, rdi
    cmp rdi, 0
    jne dg_loop
    inc rcx
dg_loop:
    cmp rax, 0
    je dg_end
    inc rcx
    mov rsi, 10
    mov rdx, 0
    div rsi
    jmp dg_loop
dg_end:
    mov rax, rcx
    ret

array_even_count:
    mov rax, 0
    mov rcx, 0
ae_loop:
    cmp rcx, rsi
    je ae_end
    mov edx, [rdi+4*rcx]
    inc rcx
    and edx, 1
    cmp edx, 1
    je ae_loop
    inc rax
    jmp ae_loop
ae_end:
    ret

array_min_value:
    mov eax, [rdi]
    mov rcx, 0
am_loop:
    cmp rcx, rsi
    je am_end
    mov edx, [rdi+4*rcx]
    inc rcx
    cmp eax, edx
    jl am_loop
    mov eax, edx
    jmp am_loop
am_end:
    ret

array_is_sorted:
    push rbx
    mov rax, 1
    mov ebx, [rdi]
    mov rcx, 1
as_loop:
    cmp rcx, rsi
    je as_end
    mov edx, [rdi+4*rcx]
    inc rcx
    cmp edx, ebx
    jl as_fail
    mov ebx, edx
    jmp as_loop
as_fail:
    mov rax, 0
as_end:
    pop rbx
    ret

convert_array:
    mov rcx, 0
ca_loop:
    cmp rcx, rsi
    je ca_end
    mov edx, [rdi+4*rcx]
    cmp edx, 0
    jge ca_skip
    not edx
    inc edx
    mov [rdi+4*rcx], edx
ca_skip:
    inc rcx
    jmp ca_loop
ca_end:
    ret

array_distinct_count:
    push rbx
    mov rax, 0
    mov rcx, 0
dc_loop:
    cmp rcx, rsi
    je dc_end
    inc rax
    mov edx, [rdi+4*rcx]
    lea rbx, [rcx+1]
dc_loop2:
    cmp rbx, rsi
    je dc_cont
    cmp edx, [rdi+4*rbx]
    je dc_fail
    inc rbx
    jmp dc_loop2
dc_fail:
    dec rax
dc_cont:
    inc rcx
    jmp dc_loop
dc_end:
    pop rbx
    ret

count_letters:
    mov rax, 0
    mov rcx, 0
    mov rdx, rsi
cl_loop:
    cmp byte [rdi+rcx], 0
    je cl_end
    cmp byte [rdi+rcx], dl
    jne cl_skip
    inc rax
cl_skip:
    inc rcx
    jmp cl_loop
cl_end:
    ret

count_words:
    mov rax, 1
    mov rcx, 0
cw_loop:
    cmp byte [rdi+rcx], 0
    je cw_end
    cmp byte [rdi+rcx], 32
    jne cw_skip
    inc rax
cw_skip:
    inc rcx
    jmp cw_loop
cw_end:
    ret

is_palindrome:
    push rbx
    mov rax, 1
    mov rcx, 0
    mov rdx, 0
ip_loop1:
    cmp byte [rdi+rdx], 0
    je ip_end1
    inc rdx
    jmp ip_loop1
ip_end1:
    dec rdx
ip_loop2:
    cmp rcx, rdx
    jge ip_end2
    mov bl, [rdi+rcx]
    mov bh, [rdi+rdx]
    cmp bl, bh
    jne ip_fail
    inc rcx
    dec rdx
    jmp ip_loop2
ip_fail:
    mov rax, 0
ip_end2:
    pop rbx
    ret

check_anagrams:
    sub rsp, 128
    mov rcx, 0
ca_fill_start:
    cmp rcx, 128
    je ca_fill_end
    mov byte [rsp+rcx], 0
    inc rcx
    jmp ca_fill_start
ca_fill_end:
    mov rcx, 0
ca_first_start:
    cmp byte [rdi+rcx], 0
    je ca_first_end
    mov rdx, 0
    mov dl, [rdi+rcx]
    inc byte [rsp+rdx]
    inc rcx
    jmp ca_first_start
ca_first_end:
    mov rcx, 0
ca_second_start:
    cmp byte [rsi+rcx], 0
    je ca_second_end
    mov rdx, 0
    mov dl, [rsi+rcx]
    dec byte [rsp+rdx]
    inc rcx
    jmp ca_second_start
ca_second_end:
    mov rax, 1
    mov rcx, 0
ca_check_start:
    cmp rcx, 128
    je ca_check_end
    cmp byte [rsp+rcx], 0
    jne ca_check_fail
    inc rcx
    jmp ca_check_start
ca_check_fail:
    mov rax, 0
ca_check_end:
    add rsp, 128
    ret

valid_student_number:
    push rbx
    mov rax, 0
    mov rcx, 0
vs_loop_start:
    cmp byte [rdi+rcx], 0
    je vs_loop_end
    cmp byte [rdi+rcx], '0'
    jl vs_end
    cmp byte [rdi+rcx], '9'
    jg vs_end
    inc rcx
    jmp vs_loop_start
vs_loop_end:
    cmp rcx, 9
    jne vs_end
    cmp byte [rdi], '0'
    jne vs_end
    mov rbx, 0
    mov rcx, 0
vs_sum_start:
    cmp rcx, 8
    je vs_sum_end
    mov rdx, 0
    mov dl, [rdi+rcx]
    sub dl, '0'
    add rbx, rdx
    cmp rcx, 2
    je vs_sum_cont
    cmp rcx, 5
    je vs_sum_cont
    add rbx, rdx
    add rbx, rdx
    cmp rcx, 0
    je vs_sum_cont
    cmp rcx, 3
    je vs_sum_cont
    cmp rcx, 6
    je vs_sum_cont
    add rbx, rdx
    add rbx, rdx
    add rbx, rdx
    add rbx, rdx
vs_sum_cont:
    inc rcx
    jmp vs_sum_start
vs_sum_end:
    mov rax, rbx
    mov rdx, 0
    mov rbx, 10
    div rbx
    mov bl, 0
    cmp rdx, 0
    je vs_div_skip
    mov bl, 10
    sub bl, dl
vs_div_skip:
    mov rax, 0
    add bl, '0'
    cmp bl, [rdi+8]
    jne vs_end
    mov rax, 1
vs_end:
    pop rbx
    ret
