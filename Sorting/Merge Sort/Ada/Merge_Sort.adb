with Ada.Containers;
with Ada.Containers.Vectors;
with Ada.Numerics.Discrete_Random;
with Ada.Text_IO;
with Ada.Integer_Text_IO;

use Ada.Containers;
use Ada.Text_IO;
use Ada.Integer_Text_IO;

procedure Merge_Sort is

   ------------------------------
   -- Constant, types, package --
   ------------------------------

   ARRAY_SIZE : constant Natural := 10;
   RANGE_MIN  : constant Integer := 1;
   RANGE_MAX  : constant Integer := 100;

   package P_Vectors is new Ada.Containers.Vectors (Positive, Integer);
   use P_Vectors;

   -----------------------
   --  Method prototype --
   -----------------------

   --  Initializing an array with default values
   function Init_Vector return Vector;

   procedure Put (Tab : Vector);

   procedure Swap (a : in out Integer; b : in out Integer);

   function Sort (T : Vector) return Vector;

   -----------------------------
   --  Declaration of methods --
   -----------------------------

   function Init_Vector return Vector
   is
      subtype T_Interval is Integer range RANGE_MIN .. RANGE_MAX;
      package P_Random is new Ada.numerics.discrete_random (T_Interval);
      use P_Random;

      seed : Generator;
      T    : Vector;
   begin
      Reset (seed);

      for i in 1 .. ARRAY_SIZE loop
         Append (T, Random (seed));
      end loop;

      return T;
   end Init_Vector;

   procedure Put (Tab : Vector)
   is
   begin
      for e of Tab loop
         Put (e, Width => 0);
         Put (";");
      end loop;
   end Put;

   procedure Swap (a : in out Integer; b : in out Integer)
   is
      c : constant Integer := a;



   begin
      a := b;
      b := c;
   end Swap;

   function Sort (T : Vector) return Vector is
      -----------------------
      --  Method prototype --
      -----------------------

      function Merge (Left, Right : in out Vector) return Vector;

      -----------------------------
      --  Declaration of methods --
      -----------------------------

      function Merge (Left, Right : in out Vector) return Vector is
         Result : Vector;
      begin
         while not Is_Empty (Left) and not Is_Empty (Right) loop
            if First_Element (Left) <= First_Element (Right) then
               Append (Result, First_Element (Left));
               Left.Delete_First;
            else
               Append (Result, First_Element (Right));
               Right.Delete_First;
            end if;
         end loop;

         while not Is_Empty (Left) loop
            Append (Result, First_Element (Left));
            Left.Delete_First;
         end loop;

         while not Is_Empty (Right) loop
            Append (Result, First_Element (Right));
            Right.Delete_First;
         end loop;

         return Result;
      end Merge;

      Left  : Vector;
      Right : Vector;
   begin
      if T.Length <= Ada.Containers.Count_Type (1) then
         return T;
      end if;

      for i in First_Index (T) .. Last_Index (T) loop
         if Ada.Containers.Count_Type (i) <= Ada.Containers.Count_Type (T.Length / 
Ada.Containers.Count_Type (2)) then
            Append (Left, T (i));
         else
            Append (Right, T (i));
         end if;
      end loop;

      Left  := Sort (Left);
      Right := Sort (Right);

      return Merge (Left, Right);
   end Sort;

   ---------------
   -- Variables --
   ---------------

   T : Vector := Init_Vector;
begin
   Put ("Array        : ");
   Put (T);
   New_Line;

   T := Sort (T);

   Put ("Sorted array : ");
   Put (T);
end Merge_Sort;
