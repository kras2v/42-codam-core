/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:30 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/22 00:49:58 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// Reset
# define RESET "\001\033[0m\002"

// Regular Colors
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\033[0;33m"
# define BLUE "\001\033[1;34m\002"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

// Bold Colors
# define BBLACK "\033[1;30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"

// Underline Colors
# define UBLACK "\033[4;30m"
# define URED "\033[4;31m"
# define UGREEN "\033[4;32m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UMAGENTA "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

// Background Colors
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGWHITE "\033[47m"

// High Intensity Colors
# define IBLACK "\033[0;90m"
# define IRED "\033[0;91m"
# define IGREEN "\033[0;92m"
# define IYELLOW "\033[0;93m"
# define IBLUE "\033[0;94m"
# define IMAGENTA "\033[0;95m"
# define ICYAN "\033[0;96m"
# define IWHITE "\033[0;97m"

// Bold High Intensity Colors
# define BIBLACK "\033[1;90m"
# define BIRED "\033[1;91m"
# define BIGREEN "\033[1;92m"
# define BIYELLOW "\033[1;93m"
# define BIBLUE "\033[1;94m"
# define BIMAGENTA "\033[1;95m"
# define BICYAN "\033[1;96m"
# define BIWHITE "\033[1;97m"

// High Intensity Backgrounds
# define BGBLACK_HI "\033[0;100m"
# define BGRED_HI "\033[0;101m"
# define BGGREEN_HI "\033[0;102m"
# define BGYELLOW_HI "\033[0;103m"
# define BGBLUE_HI "\033[0;104m"
# define BGMAGENTA_HI "\033[0;105m"
# define BGCYAN_HI "\033[0;106m"
# define BGWHITE_HI "\033[0;107m"

#endif
