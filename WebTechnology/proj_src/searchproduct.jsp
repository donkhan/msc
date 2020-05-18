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
   if (uuid == null){
         response.sendRedirect("/prod/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   System.out.println("Search Product uuid = " + uuid);
   String search_product_id = request.getParameter("search_product_id");
   if(search_product_id == null) search_product_id = "";

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

<div class="navbar">
   <a href=home.jsp?uuid="<% out.print(uuid); %>" >Home</a>
   <a href=viewproducts.jsp?uuid="<% out.print(uuid); %>" >View Products</a>
   <a href=addproduct.jsp?uuid="<% out.print(uuid); %>" >Add Product</a>
   <a href=searchproduct.jsp?uuid="<% out.print(uuid); %>" >Search Product</a>
    <a href=logout.jsp?uuid="<% out.print(uuid); %>" >Logout</a>
</div>

<h1> Product Management System </h1>
</div>

        <br><br><br>
        <form action="/prod/searchproduct.jsp" method="get">
        Product ID    : <input type="text" name="search_product_id">
        <input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
        <br><br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <button type="submit" formaction="/prod/searchproduct.jsp">Search</button>
        </form>

        <% if(!search_product_id.equals("")){ %>

        <TABLE>
          <TR><TH border=1>ID</TH><TH border=1>Name</TH><TH border=1>Category</TH><TH border=1>Price</TH></TR>
        <%
            try {
                 query = "select * from products where id = ?";
                 stmt = con.prepareStatement(query);
                 stmt.setString(1,search_product_id);
                 rs = stmt.executeQuery();
                 while (rs.next()) {
        %>
                  <TR >
                      <TD border=1> <%= rs.getString(1) %> </TD>
                      <TD border=1> <%= rs.getString(2) %> </TD>
                      <TD border=1> <%= rs.getString(3) %> </TD>
                      <TD border=1> <%= rs.getString(4) %> </TD>
                  </TR>

        <%
                 }
        %>
        </TABLE>
        <%
            } catch(Throwable t){
                t.printStackTrace();
            }
            finally {
                 if (con!=null) { con.close(); }
            }
        }
        %>

</body>
</html>
