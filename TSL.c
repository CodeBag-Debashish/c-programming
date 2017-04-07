



				while(true) {



					1. TSL Ri , M[flag];
					2. CMP Ri, #0
					3. JNZ to step 1.



					// critical section
					< CS >
					// end of critical section
					


					// try to leave critical section with notification
					4. STORE M[flag],#0				



				}