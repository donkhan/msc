<!DOCTYPE html>
<html>
    <jsp:include page="style.jsp">
        <jsp:param name="styleName" value="" />
    </jsp:include>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>


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
             %>
                <div class="navbar">
                    <a href=home.jsp?uuid="<% out.print(uuid); %>" >Home</a>
                       <a href=viewproducts.jsp?uuid="<% out.print(uuid); %>" >View Products</a>
                       <a href=addproduct.jsp?uuid="<% out.print(uuid); %>" >Add Product</a>
                       <a href=searchproduct.jsp?uuid="<% out.print(uuid); %>" >Search Product</a>
                       <a href=logout.jsp?uuid="<% out.print(uuid); %>" >Logout</a>
                </div>
                <br><br><br><br><br><br>
                Welcome to Product Management System. Please click appropriate menus to add/edit/delete/view the product types
             <%
             }else{ %>
                <div class="navbar">
                   <a href=home.jsp?uuid="<% out.print(""); %>" >Home</a>
                   <a href=viewproducts.jsp?uuid="<% out.print(""); %>" >View Products</a>
                   <a href=addproduct.jsp?uuid="<% out.print(""); %>" >Add Product</a>
                   <a href=searchproduct.jsp?uuid="<% out.print(""); %>" >Search Product</a>
                    <a href=logout.jsp?uuid="<% out.print(""); %>" >Logout</a>
                </div>
                <form action="/prod/home.jsp" method="get" align="center">
                    <br><br><br>
                    Name:
                    <input type="text" id="name" name="name"><br><br>
                    Password:
                    <input type="text" id="password" name="password"><br><br>
                    <button type="submit" formaction="/prod/home.jsp">Login</button>
                </form>
             <% }
         } catch(Throwable t){
            t.printStackTrace();
            response.sendRedirect("/prod/home.jsp");
         }
         finally {
             if (con!=null) { con.close(); }
         }
    %>
</body>
</html>
</body>
</html>