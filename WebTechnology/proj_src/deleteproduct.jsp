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
   System.out.println("Product ID "+ product_id);

   Context ctx = new InitialContext();
   Context initCtx  = (Context) ctx.lookup("java:/comp/env");
   DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");
   Connection con = ds.getConnection();
   con.setAutoCommit(false);
   PreparedStatement stmt;
   String query = "delete  from products where id = ? ";
   stmt = con.prepareStatement(query);
   stmt.setString(1,product_id);
   stmt.executeUpdate();
   con.commit();
   System.out.println("Deletion Done");

   response.sendRedirect("/sample/viewproducts.jsp?uuid=" + uuid);
 %>



</body>
</html>
