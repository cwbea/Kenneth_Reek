#ifndef _STDARG_H_
#define _STDARG_H_

typedef char *va_list;

/* Round size up to multiple of sizeof(int) */
#define _INTSIZEOF(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

/* Initialize va_list pointer ap to point just past last named argument v */
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

/* Get next argument of type t */
#define va_arg(ap, t)   (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))

/* Clean up */
#define va_end(ap)      (ap = (va_list)0)

#endif

