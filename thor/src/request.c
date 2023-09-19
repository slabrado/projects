/* request.c: Make HTTP Requests */

#include "request.h"

#include "macros.h"
#include "socket.h"

#include <stdlib.h>
#include <string.h>

/* Constants */

#define HOST_DELIMITER  "://"
#define PATH_DELIMITER  '/'
#define PORT_DELIMITER  ':'

/* Functions */

/**
 * Construct Request structure by parsing URL string into separate host, port,
 * and path components.
 *
 * @param   url         URL string to parse.
 *
 * @return  Request structure.
 **/
Request *   request_create(const char *url) {
    /* TODO: Copy data to local buffer */
    char buffer[BUFSIZ];
    strcpy(buffer, url);

    /* TODO: Skip scheme to host */
    char *host = strstr(buffer, HOST_DELIMITER);
    if (host) {
        host = host + 3;
    } else {
        host = buffer;
    }
    /* TODO: Split host:port from path */
    char *path = strchr(host, PATH_DELIMITER);
    if (path) {
        *path = '\0';
        path++;
    } else {
        path = "";
    }
    /* TODO: Split host and port */
    char *port = strchr(host, PORT_DELIMITER);
    if (port) {
        *port = '\0';
        port++;
    } else {
        port = "80";
    }
    /* TODO: Allocate Request structure */
    Request *r = calloc(1, sizeof(Request));
    /* TODO: Copy components to URL structure */
    if (r){
        r->host = strdup(host);
        r->port = strdup(port);
        r->path = strdup(path);
    }
    return r;
}

/**
 * Deallocate Request structure.
 *
 * @param   request     Request structure to deallocate.
 **/
void	    request_delete(Request *request) {
    free(request->host);
    free(request->port);
    free(request->path);
    free(request);
}

/**
 * Make a HTTP request and write the contents of the response to the specified
 * stream.
 *
 * @param   url         Make a HTTP request to this URL.
 * @param   stream      Write the contents of response to this stream.
 *
 * @return  -1 on error, otherwise the number of bytes written.
 **/
ssize_t     request_stream(Request *request, FILE *stream) {
    /* TODO: Connect to remote host and port */
    FILE *client_file = socket_dial(request->host, request->port);
    if (!client_file) {
        return -1;
    }
    /* TODO: Send request to server */
    fprintf(client_file, "GET /%s HTTP/1.0\r\n", request->path);
    fprintf(client_file, "Host: %s\r\n", request->host);
    fprintf(client_file, "\r\n");
    /* TODO: Read response status from server */
    char buffer[BUFSIZ];
    fgets(buffer, BUFSIZ, client_file);
    if (strstr(buffer, "200 OK") == NULL) {
        return -1;
    }
    /* TODO: Read response headers from server */
    size_t content_length = 0;
    while (fgets(buffer, BUFSIZ, client_file) && strlen(buffer) > 2) {
        sscanf(buffer, "Content-Length: %lu", &content_length);
    }
    /* TODO: Read response body from server */
    size_t bytesRead = 0;
    size_t bytesReadI = 0;
    while (true) {
        bytesReadI = fread(buffer, 1, BUFSIZ, client_file);
        if (bytesReadI <= 0){
            break;
        }
        bytesRead = bytesRead + bytesReadI;
        fwrite(buffer, 1, bytesReadI, stream); 
    }

    /* TODO: Close connection */
    fclose(client_file);
    /* TODO: Return number of bytes written and check if it matches Content-Length */
    if (bytesRead == content_length){
        return content_length; 
    }

    return -1;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
