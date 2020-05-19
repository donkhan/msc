<!DOCTYPE html>
<html>
   <jsp:include page="style.jsp">
            <jsp:param name="styleName" value="" />
   </jsp:include>
<body>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>

<%
   String uuid = request.getParameter("uuid");
   System.out.println("View Products uuid = " + uuid);
   if (uuid == null || uuid.equals("")){
         response.sendRedirect("/prod/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   if (uuid.equals("")){
            response.sendRedirect("/prod/home.jsp");
   }

   Context ctx = new InitialContext();
   Context initCtx  = (Context) ctx.lookup("java:/comp/env");
   DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");
   Connection con = ds.getConnection();;
   PreparedStatement stmt;
   String query = "select * from customers where uuid = ? ";
   stmt = con.prepareStatement(query);
   stmt.setString(1,uuid);
   ResultSet rs = stmt.executeQuery();
   int i = -1;
   while(rs.next()){
    i = i + 1;
   }
   rs.close();
   if(i == -1){
    response.sendRedirect("/prod/home.jsp");
   }

 %>

<%
    request.setAttribute("uuid",uuid);
    request.setAttribute("query","select * from products");
%>
<jsp:include page="navbar.jsp">
     <jsp:param name="uuid" value="${uuid}" />
</jsp:include>

<h1> Product Management System </h1>
<jsp:include page="list_products.jsp">
     <jsp:param name="uuid" value="${uuid}" />
     <jsp:param name="query" value="${query}" />
</jsp:include>


</body>
</html>