/*

1. Random Account number generator
add.acc_no = (rand() % (9000000000)) + 1000000000;

2. IFSC Code generator
s.ifs_cd = (rand() % (9000000)) + 1000000;
strcpy(s.ifsc_cd, s.ifs_cd); //The integer isnt being converted to string, tried itoa(), and explicit type casting, fix if possible

3. Random PIN generator
add.pin = (rand() % (9000)) + 1000;

*/
