.PHONY:clean

linkstack:linkstack.c
	gcc $^ -o $@

clean:
	rm linkstack
