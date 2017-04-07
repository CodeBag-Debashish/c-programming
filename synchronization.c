var
a,b,c,d,e,f,g,h,i,j,k : semaphore;
// assume all binary semaphores are initially zero
begin
	cobegin
		// S1 can always start without any lock checking
		begin S1; V(a); V(b) end;
		// after completion of S1 up() operation performed on a and b


		begin P(a); S2; V(c); V(d) end;
		// check lock a by performing down(a) first
		// If S1 is not completed, then S2 will be blocked
		// otherwise
		// after completion of S2 up() operation performed on c and d		
			

		begin P(c); S4; V(e) end;
		// check lock c by performing down(c) first
		// If S2 is not completed then S4 will be blocked
		// otherwise
		// after completion of S4 up() operation performed on e ...etc..		

		begin P(d); S5; V(f) end;
		
		begin P(e); P(f); S7; V(k) end
		
		begin P(b); S3; V(g); V(h) end;
		
		begin P(g); S6; V(i) end;
		
		begin P(h); P(i); S8; V(j) end;
		
		begin P(j); P(k); S9 end;
	coend
end;