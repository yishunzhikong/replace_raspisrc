#ifndef _MYSRCFILE_H_
#define _MYSRCFILE_H_

//出厂源
#define		factory_file1	"\
deb http://raspbian.raspberrypi.org/raspbian/ stretch main contrib non-free rpi\r\n\
#Uncomment line below then \'apt-get update\' to enable \'apt-get source\'\r\n\
#deb-src http://raspbian.raspberrypi.org/raspbian/ stretch main contrib non-free rpi\r\n"
#define		factory_file2	"\
deb http://archive.raspberrypi.org/debian/ stretch main ui\r\n\
#Uncomment line below then \'apt-get update\' to enable \'apt-get source\'\r\n\
#deb-src http://archive.raspberrypi.org/debian/ stretch main ui\r\n"

//电子科技大学
#define UESTC1 "\
deb http://mirrors.ustc.edu.cn/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define UESTC2 "\
deb http://mirrors.ustc.edu.cn/archive.raspberrypi.org/debian/ jessie main ui\r\n"

//清华大学
#define THU1 "\
deb http://mirrors.tuna.tsinghua.edu.cn/raspbian/raspbian/ stretch main contrib non-free rpi\r\n\
deb-src http://mirrors.tuna.tsinghua.edu.cn/raspbian/raspbian/ stretch main contrib non-free rpi\r\n"
#define THU2 "\
deb http://mirror.tuna.tsinghua.edu.cn/raspberrypi/ stretch main ui\r\n\
deb-src http://mirror.tuna.tsinghua.edu.cn/raspberrypi/ stretch main ui\r\n"

//阿里巴巴
#define ALIYUN1 "\
deb http://mirrors.aliyun.com/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define ALIYUN2 "\
deb http://mirrors.aliyun.com/raspbian/raspbian/ jessie main ui\r\n"

//华中科技大学
#define HUST1 "\
deb http://mirrors.hustunique.com/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define HUST2 "\
deb http://mirrors.hustunique.com/raspbian/raspbian/ jessie main ui\r\n"

//华南农业大学(华南用户)
#define SCAU1 "\
deb http://mirrors.scau.edu.cn/raspbian/ jessie main contrib non-free rpi\r\n"
#define SCAU2 "\
deb http://mirrors.scau.edu.cn/raspbian/ jessie main ui\r\n"

//大连东软信息学院源(北方用户)
#define DNUI1 "\
deb http://mirrors.neusoft.edu.cn/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define DNUI2 "\
deb http://mirrors.neusoft.edu.cn/raspbian/raspbian/ jessie main ui\r\n"

//重庆大学源(中西部用户)
#define CQU1 "\
deb http://mirrors.cqu.edu.cn/Raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define CQU2 "\
deb http://mirrors.cqu.edu.cn/Raspbian/raspbian/ jessie main ui\r\n"

//新加坡国立大学
#define NUS1 "\
deb http://mirror.nus.edu.sg/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define NUS2 "\
deb http://mirror.nus.edu.sg/raspbian/raspbian/ jessie main ui\r\n"

//牛津大学
#define Oxford1 "\
deb http://mirror.ox.ac.uk/sites/archive.raspbian.org/archive/raspbian/ jessie main contrib non-free rpi\r\n"
#define Oxford2 "\
deb http://mirror.ox.ac.uk/sites/archive.raspbian.org/archive/raspbian/ jessie main ui\r\n"

//韩国KAIST大学
#define KAIST1 "\
deb http://ftp.kaist.ac.kr/raspbian/raspbian/ jessie main contrib non-free rpi\r\n"
#define KAIST2 "\
deb http://ftp.kaist.ac.kr/raspbian/raspbian/ jessie main ui\r\n"

#endif
