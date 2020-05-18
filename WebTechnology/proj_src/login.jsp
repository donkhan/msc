<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>

<html>
<head>
<title>Product Management System</title>
</head>
<body bgcolor=white>


<body>

    <%
        String name = request.getParameter("name");
        String password = request.getParameter("password");
        System.out.println("name = " + name + " pw = " + password);
        Context ctx = new InitialContext();

        Context initCtx  = (Context) ctx.lookup("java:/comp/env");
        DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");

        Connection con = null;
        PreparedStatement stmt;
        try {
             con = ds.getConnection();
             con.setAutoCommit(false);
             String query = "select * from customers where name = ? and password = ?";
             System.out.println(query);
             stmt = con.prepareStatement(query);
             stmt.setString(1,name);
             stmt.setString(2,password);
             ResultSet rs = stmt.executeQuery();
             int i = -1;
             while(rs.next()){
                i = i + 1;
             }
             rs.close();
             if(i == 0){
                String uuid=UUID.randomUUID().toString();
                stmt = con.prepareStatement("UPDATE CUSTOMERS " +
                                     "SET uuid = ? " +
                                     "WHERE NAME = ?");
                         stmt.setString(1, uuid);
                         stmt.setString(2, name);
                         stmt.executeUpdate();
                con.commit();
                stmt.close();
                response.sendRedirect("/sample/home.jsp?uuid="+uuid);
             }
         } catch(Throwable t){
            t.printStackTrace();
            response.sendRedirect("login.html");
         }
         finally {
             if (con!=null) { con.close(); }
         }
    %>

</body>
</html>
