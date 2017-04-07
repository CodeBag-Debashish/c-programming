




					//shared variables

					int turn;
					int interested_flag[2];
					//


					// code for process p and the other process is q

					do {
						
						interested_flag[p] = TRUE;
						turn = p;
						while(turn == p && interested_flag[q] == TRUE) {
							// loop
						}


						// critical seciton
						< CS >
						// critical section ends


						// leave critical section try
						interested_flag[p] = FALSE;
						// successfully left CS

						// reminder section
						printf("hi-hello-etc...\n");

					}