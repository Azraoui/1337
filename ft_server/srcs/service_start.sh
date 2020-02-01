#!/bin/bash
chown -R mysql: /var/lib/mysql
service mysql start
service php7.3-fpm start
nginx -g 'daemon off;'
service mysql start
service nginx start
service php7.3-fpm start
bin/bash
