<!DOCTYPE html>
<html>
<body>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>
<%
   String uuid = request.getParameter("uuid");
   if (uuid == null){
         response.sendRedirect("/sample/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   System.out.println("Delete Product uuid = " + uuid);
   String product_id = request.getParameter("product_id");
   System.out.println(product_id);

 %>



</body>
</html>
