# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:56:30 by ael-azra          #+#    #+#              #
#    Updated: 2020/01/31 18:20:34 by ael-azra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#install and update:

apt-get update
apt-get upgrade -y
apt-get install -y nginx
apt-get install -y vim wget
apt-get install -y curl
apt-get install expect -y
apt-get install -y debconf-utils
apt-get install -y gnupg
apt-get install -y lsb-release
apt-get install -y libnss3-tools

#mysql:

apt-get update
apt-get upgrade -y
wget http://repo.mysql.com/mysql-apt-config_0.8.14-1_all.deb
expect -c "
set timeout 10
spawn dpkg -i mysql-apt-config_0.8.14-1_all.deb
expect \"Which MySQL product do you wish to configure? \"
send \"1\r\"
expect \"Which server version do you wish to receive? \"
send \"1\r\"
expect \"Which MySQL product do you wish to configure? \"
send \"4\r\"
expect eof
"
apt-get update
export DEBIAN_FRONTEND=noninteractive
echo "mysql-server mysql-server/root_password password root" | debconf-set-selections
echo "mysql-server mysql-server/root_password_again password root" | debconf-set-selections
apt-get update
apt-get install -y mysql-server
service mysql start

mysql -uroot -proot -e "CREATE DATABASE data"
mysql -uroot -proot -e "CREATE USER 'data'@'localhost' IDENTIFIED BY 'paspas'"
mysql -uroot -proot -e "GRANT ALL PRIVILEGES ON *.* TO 'data'@'localhost'"
mysql -udata -ppaspas data < localhost.sql
#phpmyadmin wordpress php

wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap
curl -LO https://wordpress.org/latest.tar.gz

bin/bash
