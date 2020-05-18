<!DOCTYPE html>
<html>
    <jsp:include page="style.jsp">
          <jsp:param name="style" value="" />
    </jsp:include>
<body>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>
<%
   String uuid = request.getParameter("uuid");
   System.out.println("Logout uuid = " + uuid);
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
        response.sendRedirect("/sample/home.jsp");
    }

    if(!uuid.equals("")){
         con.setAutoCommit(false);
        stmt = con.prepareStatement("UPDATE CUSTOMERS " +
                                          "SET uuid = ? " +
                                          "WHERE uuid = ?");
        stmt.setString(1, "");
        stmt.setString(2, uuid);
        stmt.executeUpdate();
        con.commit();
        stmt.close();
        response.sendRedirect("/prod/home.jsp");
    }
 %>



</body>
</html>
