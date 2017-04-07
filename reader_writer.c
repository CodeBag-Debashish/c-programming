int readers_count = 0;
semaphore mutex = 1; // binary semaphore
semaphore db = 1;    // binary semaphore

void reader() {
	while(TRUE) {
		down(mutex);
		readers_count = readers_count + 1;
		if(readers_count == 1) down(db);
		up(mutex);

		< access DB >
		
		down(mutex);
		readers_count = readers_count - 1;
		if(readers_count == 0) up(db);
		up(mutex);
	}
}

void writer() {
	while(TRUE) {
		down(db);

		< access DB >
		
		up(db);
	}
}