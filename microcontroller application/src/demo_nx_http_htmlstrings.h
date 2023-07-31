

#define htmlwrite(p,s)  (nx_packet_data_append(p,s,(ULONG)strlen((const char*)s), server_ptr-> nx_http_server_packet_pool_ptr,NX_WAIT_FOREVER))

#define htmlresponse "HTTP/1.0 200 \r\nContent-Type: text/html\r\n\r\n"

#define htmltag "<HTML>"
#define htmlendtag "</HTML>"

#define sysvars_anchor_tag "<I> <a href=\"/\" > System Variables </a> </I>"

#define bodytag "<body bgcolor=\"#FFFF00\" >"
#define bodyendtag "</body>"

#define hrline "<HR SIZE=6 WIDTH=\"90%\" NOSHADE COLOR=\"black\"  >"

#define titleline "<HEAD><TITLE>NetX HTTP Server</TITLE></HEAD>\r\n"
#define h1line " <H1 ALIGN=\"center\"> <img src=\"/nxlogo.gif\"> NetX HTTP Server Demonstration <img src=\"/txlogo.gif\"></H1>\r\n"
#define tabletag "<TABLE BORDER=\"1\" ALIGN=\"center\" >"
#define tableendtag "</TABLE>"
#define captiontag "<CAPTION ALIGN=\"top\" >"
#define captionendtag "</CAPTION>"
#define trtag "<TR>"
#define trendtag "</TR>"
#define tdtag "<TD>"
#define tdendtag "</TD>"

#define anchortag "<A href=\"/test.htm?Display="
#define gtchar "\">"
#define anchorendtag "</A>"

#define refresh "<H1 ALIGN=\"center\">"   "<meta http-equiv=\"refresh\" content=\"2\">"   "</H1>\r\n"

