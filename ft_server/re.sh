docker system prune
docker stop $(docker ps -a -q)
docker rm $(docker ps -a -q)
docker rmi $(docker image ls -a -q)
docker image build -t test .
docker run -d -p 80:80 -p 443:443 test
