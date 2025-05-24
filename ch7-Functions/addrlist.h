/*
** Declarations for the address list module.
*/

/*
** Data characteristics
**
** Maximum lengths of the various data (includes space for the
** terminating NUL byte), and maximum number of addresses.
*/

#define NAME_LENGTH     30   // Longest name allowed (including null terminator)
#define ADDR_LENGTH     100  // Longest address allowed
#define PHONE_LENGTH    11   // Longest phone number allowed
#define MAX_ADDRESSES   1000 // Maximum number of addresses allowed

/*
** Interface functions
**
** Given a name, find the corresponding address.
*/
char const *lookup_address(char const *name);

/*
** Given a name, find the corresponding phone number.
*/
char const *lookup_phone(char const *name);

