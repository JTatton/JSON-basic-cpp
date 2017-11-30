# JSON Easy C++


## Project Aim

The aim of this project is to make a simple class that can be used for retrieving data from a JSON file.

---

## Reason for Project

I just want a simple way to get information from a JSON file to use in other programs. I have attempted to use the numerous other C++ JSON programs/libraries which are all much more feature rich but I struggle to get to work nicely for what I want from them. This is in no way a replacement to those, especially for "power users", but more a challenge to myself to make something I can use in the future.

---

## JSON BNF Grammar

object      ::=     '{' '}' | '{' members '}'
members     ::=     pair | pair ',' members
pair        ::=     string ':' value
array       ::=     '[' ']' | '[' elements ']'
elements    ::=     value | value ',' elements
value       ::=     string | number | object | array | 'true' | 'false' | 'null'

string      ::=     '"' '"' | '"' chars '"'
chars       ::=     char | char chars
char        ::=     *Any Unicode Character except* '"' *or* '\' | '\"' | '\\' | '\/' | '\b' | '\f' | '\n' | '\r' | '\t' | '\u' *four hex digits*
number      ::= ['-'] ('0' | digit19) digit* ['.' digit digit*] [('e'|'E') ['+'|'-'] digit digit*] 