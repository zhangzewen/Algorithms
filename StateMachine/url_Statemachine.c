#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct http_parse_st{
	char *method_start;
	char *method_end;
	char *path_start;
	char *path_end;
	char *version_start;
	char *version_end;
};


void do_method(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("method = %s\n", buff);
}

void do_path(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("path = %s\n", buff);
}

void do_version(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("version = %s\n", buff);
}


typedef struct http_parse_st http_parse_t;
int parse_http_request_line(http_parse_t *r, char *buff)
{
    char  ch;
    char  *p;
		char  *tmp;
    enum {
        sw_start = 0,
        sw_method,
        sw_spaces_before_uri,
				sw_uri,
				sw_spaces_after_uri,
				sw_spaces_before_version,
				sw_version,
				sw_request_line_parse_almost_done,
				sw_request_line_parse_done,
				sw_almost_done,
				sw_done
				
    } state;

    state = sw_start;

    for (p = buff; ; p++) {
        ch = *p;
				
				if (ch == '\0' || ch == '0') {
					break;
				}

        switch (state) {

        case sw_start:
            r->method_start = p;

            if (ch == '\r' || ch == '\n') {
                break;
            }

            if (ch < 'A' || ch > 'Z') {
                return -1;
            }

            state = sw_method;
            break;

        case sw_method:
            if (ch == ' ') {
                r->method_end = p;
							
								do_method(r->method_start, r->method_end);

                state = sw_spaces_before_uri;
                break;
            }

            if (ch < 'A' || ch > 'Z') {
                return -1;
            }

            break;

        case sw_spaces_before_uri:

            if (ch == '/') {
                r->path_start = p;
                state = sw_uri;
                break;
            }

				case sw_uri:
						if (ch == ' ') {
							state = sw_spaces_before_version;
							r->path_end = p;
							do_path(r->path_start, r->path_end);
						} 

						break;
				case sw_spaces_before_version:
						if (ch == 'H') {
							state = sw_version;
							r->version_start = p;
							break;
						}
						
				case sw_version:
						if (ch == '\r') {
							state = sw_request_line_parse_almost_done;
							r->version_end = p;
							do_version(r->version_start, r->version_end);
						}	

						break;
				case sw_request_line_parse_almost_done:
						if (ch == '\n') {
							state = sw_request_line_parse_done;
						}
						break;
				case sw_request_line_parse_done:
						if (ch == '\r') {
							tmp = p;
							state = sw_almost_done;
						} else {
							return -1;
							
						}
						break;
				case sw_almost_done:
						if (ch == '\n' && *tmp == '\r') {
							state = sw_done;
						}else {
							return -1;
						}
						break;

				default:
						break;

        }
    }
    return 0;
}


int main(int args, char *argv[])
{
	char url_1[] = "GET / HTTP/1.1\r\n\r\n";
	char url_2[] = "GET /html/index.php HTTP/1.1\r\n\r\n";
//	char url_2[] = "GET / HTTP/1.1\r\nHost: www.baidu.com\r\n\r\n";
//	char url_3[] = "GET /html/index.php HTTP/1.1\r\nHoset: www.baidu.com\r\n\r\n";
	int ret = 0;
	
	http_parse_t r;
	
	ret = parse_http_request_line(&r, url_2);
	if (ret == -1) {
		puts("error!");
	}

	if (ret == 0) {
		puts("ok,done");
	}
	return 0;
	
}

