/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:16:08 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 15:16:53 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

static int	ft_putnbr(long long nb)
{
	unsigned long long	n;
	int					count;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
		count++;
	}
	else
		n = nb;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	n = n % 10 + 48;
	count += write(1, &n, 1);
	return (count);
}

static int	ft_puthex(unsigned long nb, int uplow, int p)
{
	char	*base;
	int		count;

	count = 0;
	if (p)
		count += write(1, "0x", 2);
	if (uplow)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb > 15)
		count += ft_puthex(nb / 16, uplow, 0);
	count += write(1, &base[nb % 16], 1);
	return (count);
}

// ************************************************************************** //
// ft_puthex is called both to return the address, the capital hex, and regular
// hex. We do this by making if statements which will return 1/0 depending on
// what we look for. The correct application will be used in ft_vargs.
// ************************************************************************** //

static int	ft_vargs(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
	{
		c = va_arg(args, int);
		size += write (1, &c, 1);
	}
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		size += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'p')
		size += ft_puthex(va_arg(args, unsigned long), 0, 1);
	else if (c == 'x')
		size += ft_puthex(va_arg(args, unsigned int), 0, 0);
	else if (c == 'X')
		size += ft_puthex(va_arg(args, unsigned int), 1, 0);
	else if (c == '%')
		size += write(1, "%", 1);
	return (size);
}

// ************************************************************************** //
// ft_vargs will apply the correct functions to our format parameter in printf
// ************************************************************************** //

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	va_start(args, format);
	if (!format)
		return (0);
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			size += ft_vargs(format[++i], args);
		else
			size += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (size);
}

// ************************************************************************** //
// ft_printf will initialize our va_list, connecting our parameter 'char
// * format' to the arguments in ft_vargs. While we look at our format, we check
// for the '%' condition that will be the key signal for the ft_vargs call.
// As ft_printf returns an int, we return the 'size' variable, and call our
// printing functions in ft_vargs.
// ************************************************************************** //
