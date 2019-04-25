CC=gcc
CPP=g++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2
CPFLAGS=-std=c++11 -pedantic -Wall -Wextra -O2
LIB=htab_lookup_add.o htab_iterator_next.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o htab_init.o htab_hash_function.o htab_size.o htab_bucket_count.o htab_end.o htab_begin.o htab_clear.o htab_free.o
LIBDYN=htab_lookup_add_dyn.o htab_iterator_next_dyn.o htab_iterator_get_key_dyn.o htab_iterator_get_value_dyn.o htab_iterator_set_value_dyn.o htab_init_dyn.o htab_hash_function_dyn.o htab_size_dyn.o htab_bucket_count_dyn.o htab_end_dyn.o htab_begin_dyn.o htab_clear_dyn.o htab_free_dyn.o

all: tail tail2 wordcount wordcount-dynamic libhtab.a libhtab.so

tail: tail.o
	$(CC) $(CFLAGS) -o tail tail.o

tail2: tail2.o
	$(CPP) $(CPFLAGS) -o tail2 tail2.o

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c

tail2.o: tail2.cc
	$(CPP) $(CPFLAGS) -c tail2.cc

wordcount: wordcount.c htab.h libhtab.a
	$(CC) $(CFLAGS) $^ -o $@ -g

wordcount-dynamic: wordcount.c htab.h libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

libhtab.a: $(LIB)
	ar -cq $@ $^

libhtab.so: $(LIBDYN)
	$(CC) -fPIC $(CFLAGS) -shared $^ -o $@

htab.o: htab.c htab.h
	$(CC) $(CFLAGS) -c htab.c

htab_lookup_add.o: htab_lookup_add.c  
	$(CC) $(CFLAGS) -c htab_lookup_add.c -o $@

htab_iterator_next.o: htab_iterator_next.c  
	$(CC) $(CFLAGS) -c htab_iterator_next.c -o $@

htab_iterator_get_key.o: htab_iterator_get_key.c  
	$(CC) $(CFLAGS) -c htab_iterator_get_key.c -o $@

htab_iterator_get_value.o: htab_iterator_get_value.c  
	$(CC) $(CFLAGS) -c htab_iterator_get_value.c -o $@

htab_iterator_set_value.o: htab_iterator_set_value.c  
	$(CC) $(CFLAGS) -c htab_iterator_set_value.c -o $@

htab_init.o: htab_init.c  
	$(CC) $(CFLAGS) -c htab_init.c -o $@

htab_hash_function.o: htab_hash_function.c 
	$(CC) $(CFLAGS) -c htab_hash_function.c -o $@

htab_size.o: htab_size.c  
	$(CC) $(CFLAGS) -c htab_size.c -o $@

htab_bucket_count.o: htab_bucket_count.c  
	$(CC) $(CFLAGS) -c htab_bucket_count.c -o $@
 
htab_end.o: htab_end.c  
	$(CC) $(CFLAGS) -c htab_end.c -o $@

htab_begin.o: htab_begin.c  
	$(CC) $(CFLAGS) -c htab_begin.c -o $@

htab_clear.o: htab_clear.c
	$(CC) $(CFLAGS) -c htab_clear.c -o $@

htab_free.o: htab_free.c  
	$(CC) $(CFLAGS) -c htab_free.c -o $@

htab_dyn.o: htab.c htab.h
	$(CC) $(CFLAGS) -fPIC -c htab.c

htab_lookup_add_dyn.o: htab_lookup_add.c  
	$(CC) $(CFLAGS) -fPIC -c htab_lookup_add.c -o $@

htab_iterator_next_dyn.o: htab_iterator_next.c  
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_next.c -o $@

htab_iterator_get_key_dyn.o: htab_iterator_get_key.c  
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_get_key.c -o $@

htab_iterator_get_value_dyn.o: htab_iterator_get_value.c  
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_get_value.c -o $@

htab_iterator_set_value_dyn.o: htab_iterator_set_value.c  
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_set_value.c -o $@

htab_init_dyn.o: htab_init.c  
	$(CC) $(CFLAGS) -fPIC -c htab_init.c -o $@

htab_hash_function_dyn.o: htab_hash_function.c 
	$(CC) $(CFLAGS) -fPIC -c htab_hash_function.c -o $@

htab_size_dyn.o: htab_size.c  
	$(CC) $(CFLAGS) -fPIC -c htab_size.c -o $@

htab_bucket_count_dyn.o: htab_bucket_count.c  
	$(CC) $(CFLAGS) -fPIC -c htab_bucket_count.c -o $@
 
htab_end_dyn.o: htab_end.c  
	$(CC) $(CFLAGS) -fPIC -c htab_end.c -o $@

htab_begin_dyn.o: htab_begin.c  
	$(CC) $(CFLAGS) -fPIC -c htab_begin.c -o $@

htab_clear_dyn.o: htab_clear.c
	$(CC) $(CFLAGS) -fPIC -c htab_clear.c -o $@

htab_free_dyn.o: htab_free.c  
	$(CC) $(CFLAGS) -fPIC -c htab_free.c -o $@

clean:
	rm -f *.o
	clear