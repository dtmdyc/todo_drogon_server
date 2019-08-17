rsync -avz --progress . kapil@95.216.152.135:/home/kapil/jdrogon
rsync -avz --progress /home/kapili3/fileuploads/ kapil@95.216.152.135:/home/kapil/fileuploads/

cd /home/kapili3/k/scert
rsync -avz --progress . kapil@95.216.152.135:/srv/http/react/.well-known/acme-challenge

sudo pacman -S cmake
sudo pacman -S qt
sudo pacman -S libpqxx  --- not working
sudo pacman -S boost boost-libs

https://github.com/trizen/trizen#installation
git clone https://aur.archlinux.org/trizen.git
cd trizen
makepkg -si

sudo pacman -S postgresql-libs

sudo pacman -R mariadb mariadb-libs mariadb-clients
mariadb must not installed otherwise it requires all libs of it.

I installed libpqxx from source and it works:
https://github.com/jtv/libpqxx
include_directories(/usr/local/include)

https://github.com/an-tao/drogon/wiki/02-Installation#Drogon-Installation
git clone https://github.com/an-tao/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
#instead use cmake-gui .. to remove mysql paths and USE_MYSQL = false
make && sudo make install
cd ..
cd ..
rm -rf drogon

sudo pacman -S jsoncpp range-v3

# regular task
ssh kapil@95.216.152.135
cd /home/kapil/jdrogon/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./jdragon

# 
























CREATE TABLE setting.temp_image_id (
  id      bigserial NOT NULL,
  "name"  text NOT NULL,
  size    bigint NOT NULL,
  "type"  text NOT NULL,
  /* Keys */
  CONSTRAINT temp_images_pkey
    PRIMARY KEY (id)
) WITH (
    OIDS = FALSE
  );

ALTER TABLE setting.temp_image_id
  OWNER TO postgres;