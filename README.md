# replace_raspisrc
这是一个替换树莓派源的小工具
说明：
	1.软件用于将树莓派源替换为国内源
	2.软件支持替换国内源、恢复出厂源、自动备份以及备份还原
	3.软件内所有源均在“mysrcfile.h”定义为字符串
	4.软件000仅在树莓派3B上2018-6-27更新的系统000上测试过，其他树莓派板卡及系统请自行测试
	5.每次换源均会自动备份，备份文件保存在本软件目录下，后缀“.old”，若目录下存在备份，将不再继续备份
使用方法：
	0.请用pi用户执行
	1.首次运行shell执行“sudo sh /yourpath/build.sh”
	2.首次运行后将生成可执行文件“main”,之后shell执行“sudo /yourpath/main”即可
	3.“yourpath”本程序目录
