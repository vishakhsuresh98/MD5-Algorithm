CC = g++ -std=c++11

all: main.o alphabet_to_hex.o append_length.o bin_to_hex.o binary_add.o dec_to_bin.o dec_to_hex.o encrypt.o get_constant_k.o get_process_p.o get_shift.o get_w.o hex_to_bin.o binary_and.o binary_not.o binary_or.o binary_xor.o padding.o shift_left.o
	$(CC) main.o alphabet_to_hex.o append_length.o bin_to_hex.o binary_add.o dec_to_bin.o dec_to_hex.o encrypt.o get_constant_k.o get_process_p.o get_shift.o get_w.o hex_to_bin.o binary_and.o binary_not.o binary_or.o binary_xor.o padding.o shift_left.o
main.o: main.cpp encrypt.h hex_to_bin.h bin_to_hex.o alphabet_to_hex.h
	$(CC) -c main.cpp	
alphabet_to_hex.o: alphabet_to_hex.cpp alphabet_to_hex.h dec_to_hex.h
	$(CC) -c alphabet_to_hex.cpp
append_length.o: append_length.cpp append_length.h
	$(CC) -c append_length.cpp
bin_to_hex.o: bin_to_hex.cpp bin_to_hex.h
	$(CC) -c bin_to_hex.cpp
binary_add.o: binary_add.cpp binary_add.h
	$(CC) -c binary_add.cpp
binary_and.o: binary_and.cpp binary_and.h
	$(CC) -c binary_and.cpp
binary_not.o: binary_not.cpp binary_not.h
	$(CC) -c binary_not.cpp
binary_or.o: binary_or.cpp binary_or.h
	$(CC) -c binary_or.cpp
binary_xor.o: binary_xor.cpp binary_xor.h
	$(CC) -c binary_xor.cpp
dec_to_bin.o: dec_to_bin.cpp dec_to_bin.h 
	$(CC) -c dec_to_bin.cpp	
dec_to_hex.o: dec_to_hex.cpp dec_to_hex.h 
	$(CC) -c dec_to_hex.cpp	
encrypt.o: encrypt.cpp encrypt.h bin_to_hex.h padding.h append_length.h hex_to_bin.h get_constant_k.h get_process_p.h get_shift.h get_w.h shift_left.h binary_add.h
	$(CC) -c encrypt.cpp
get_constant_k.o: get_constant_k.cpp get_constant_k.h hex_to_bin.h
	$(CC) -c get_constant_k.cpp
get_process_p.o: get_process_p.cpp get_process_p.h binary_and.h binary_not.h binary_or.h binary_xor.h
	$(CC) -c get_process_p.cpp
get_shift.o: get_shift.cpp get_shift.h
	$(CC) -c get_shift.cpp	
get_w.o: get_w.cpp get_w.h binary_xor.h shift_left.h
	$(CC) -c get_w.cpp
hex_to_bin.o: hex_to_bin.cpp hex_to_bin.h
	$(CC) -c hex_to_bin.cpp
padding.o: padding.cpp padding.h
	$(CC) -c padding.cpp
shift_left.o: shift_left.cpp shift_left.h 
	$(CC) -c shift_left.cpp		
clean:
	rm *.o
	rm a.out