while (true) 
    {
       state[i] = interested;  /* declare interest */

       while (state[j]  == interested);  /* stay clear till safe */

       <<< critical section >>>

       state[i] = notinterested;  /* we’re done */

       <<< code outside critical section >>>
    }
