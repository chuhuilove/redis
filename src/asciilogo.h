/*
 * Copyright (c) 2009-2012, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

const char *ascii_logo =
	"																																\n"
	"			   ii.										   ;9ABH,																\n"
	"			  SA391,									.r9GG35&G																\n"
	"			  &#ii13Gh; 							  i3X31i;:,rB1																\n"
	"			  iMs,:,i5895,						   .5G91:,:;:s1:8A																\n"
	"			   33::::,,;5G5,					 ,58Si,,:::,sHX;iH1 		Redis %s (%s/%d) %s bit 							\n"
	"				Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG 															\n"
	"				.G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8 		Running in %s mode  								\n"
	"			   :SB9s:,............................,,,.,,,SASh53h,1G.		Port: %d    										\n"
	"			.r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,		PID: %ld    										\n"
	"		  ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi															\n"
	"		i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1															\n"
	"	   59;.....,.	  .,,,,,,,,,,,...		 .............,..:1;.:&s			  https://github.com/chuhuilove 				\n"
	"	  s8,..;53S5S3s.   .,,,,,,,.,.. 	 i15S5h1:.........,,,..,,:99															\n"
	"	  93.:39s:rSGB@A;  ..,,,,.....	  .SG3hhh9G&BGi..,,,,,,,,,,,,.,83															\n"
	"	  G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh															\n"
	"	  Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX: 														\n"
	"	 ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;	 ....,,,,,,,,S8 														\n"
	"	 X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs	   ...,,,,,,,:Gs														\n"
	"	r8, 	   ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r. 		 .,,,,,,,.rX:														\n"
	"  :9, .	.:,..,:;;;::,.,,,,,..		   .,,. 			  ..,,,,,,.59														\n"
	" .Si	   ,:.i8HBMMMMMB&5,.... 				   .			.,,,,,.sMr														\n"
	" SS	   :: h@@@@@@@@@@#; .					  ...  .		 ..,,,,iM5														\n"
	" 91  .    ;:.,1&@@@@@@MXs. 						   .		  .,,:,:&S														\n"
	" hS ....  .:;,,,i3MMS1;..,..... .	.	  ...					  ..,:,.99														\n"
	" ,8; ..... .,:,..,8Ms:;,,,...									   .,::.83														\n"
	"  s&: ....  .sS553B@@HX3s;,.	 .,;13h.							.:::&1														\n"
	"	SXr  .	...;s3G99XA&X88Shss11155hi. 							,;:h&,														\n"
	"	 iH8:  . ..   ,;iiii;,::,,,,,.								   .;irHA														\n"
	"	  ,8X5;   . 	....... 									  ,;iihS8Gi 													\n"
	"		 1831,												   .,;irrrrrs&@ 													\n"
	"		   ;5A8r.											 .:;iiiiirrss1H 													\n"
	"			 :X@H3s.......								  .,:;iii;iiiiirsrh 													\n"
	"			  r#h:;,...,,.. .,,:;;;;;:::,...			  .:;;;;;;iiiirrss1 													\n"
	"			 ,M8 ..,....,.....,,::::::,,... 		.	  .,;;;iiiiiirss11h 													\n"
	"			 8B;.,,,,,,,.,..... 		 .			 ..   .:;;;;iirrsss111h 													\n"
	"			i@5,:::,,,,,,,,.... .					. .:::;;;;;irrrss111111 													\n"
	"			9Bi,:,,,,...... 					   ..r91;;;;;iirrsss1ss1111 													\n"
	"																																\n"
	"																																\n"
	"																																\n"
	"						  _ooOoo_																								\n"
	"						 o8888888o																								\n"
	"						 88\" . \"88																							\n"
	"						 (| -_- |)																								\n"
	"						 O\  =	/O																								\n"
	"					  ____/`---'\____																							\n"
	"					.'	\\| 	|//  `. 																						\n"
	"				   /  \\|||  :	|||//  \																						\n"
	"				  /  _||||| -:- |||||-	\																						\n"
	"				  |   | \\\  -	/// |	|																						\n"
	"				  | \_|  ''\---/''	|	|																						\n"
	"				  \  .-\__	`-`  ___/-. /																						\n"
	"				___`. .'  /--.--\  `. . __																						\n"
	"			 ."" '<  `.___\_<|>_/___.'	>'"".																					\n"
	"			| | :  `- \`.;`\ _ /`;.`/ - ` : | | 																				\n"
	"			\  \ `-.   \_ __\ /__ _/   .-` /  / 																				\n"
	"	   ======`-.____`-.___\_____/___.-`____.-'======																			\n"
	"						  `=---='																								\n"
	"	   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^																			\n"
	"				  佛祖保佑		  永无BUG 																					    \n"
	"		 佛曰:																												    \n"
	"				写字楼里写字间，写字间里程序员；																				\n"
	"				程序人员写程序，又拿程序换酒钱。																				\n"
	"				酒醒只在网上坐，酒醉还来网下眠；																				\n"
	"				酒醉酒醒日复日，网上网下年复年。																				\n"
	"				但愿老死电脑间，不愿鞠躬老板前；																				\n"
	"				奔驰宝马贵者趣，公交自行程序员。																				\n"
	"				别人笑我忒疯癫，我笑自己命太贱；																				\n"
	"				不见满街漂亮妹，哪个归得程序员？																				\n"
	"																																\n"
	"																																\n\n";
