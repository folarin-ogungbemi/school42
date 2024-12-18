#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_print_char(va_list args);
size_t	ft_print_str(va_list args);
size_t	ft_print_dec(va_list args);
size_t	ft_print_hexx(va_list args);
size_t	ft_print_hexl(va_list args);
size_t	ft_print_ptr(va_list args);
size_t	ft_print_u(va_list args);
size_t	ft_print_percent(void);
#endif
