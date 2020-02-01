# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 09:28:04 by ael-azra          #+#    #+#              #
#    Updated: 2020/02/01 13:48:43 by ael-azra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
MAINTAINER ael-azra <ael-azra@student.1337.ma>
COPY ./srcs/setup.sh ./
COPY ./srcs/service_start.sh ./

EXPOSE 80 443
COPY ./srcs/localhost.sql ./
RUN sh setup.sh
RUN tar -zxvf latest.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ phpmyadmin
RUN cp -rf phpmyadmin ./var/www/html
RUN cp -rf phpmyadmin usr/share/
RUN rm /var/www/html/wordpress/wp-config-sample.php
COPY srcs/wp-config.php /var/www/html/wordpress
COPY srcs/default etc/nginx/sites-available/
COPY srcs/localhost.crt /etc/ssl/certs/
COPY srcs/localhost.key /etc/ssl/private/
RUN sh clean.sh

CMD bash service_start.sh
