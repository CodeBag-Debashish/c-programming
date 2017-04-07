




                        boolean choosing[n];
                        int number[n];
                        
                        while (true) {
                            

                    1      choosing[i] = true;

                    2      number[i] = 1 + getmax(number[], n);

                    3      choosing[i] = false;
                            
                            
                    4       for (int j = 0; j < n; j++){
                    5           while (choosing[j]) { };
                    6           while ((number[j] != 0) && (number[j],j) < (number[i],i)) { 
                                    /*do nothing*/
                                };
                            }
                            



                            
                            < Critical Section >



                    7      number[i] = 0;
                            /* remainder */;

                       
                        }
