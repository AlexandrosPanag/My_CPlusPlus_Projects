//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//



simple node
{
    parameters:
        @node;
        //� � �������������
        int xCor;// = uniform(0,1000,1);
        int yCor;// = uniform(0,1000,1);
    gates:
        inout gate[];
}

network GRG
{
    parameters:
        int numNodes = 100; //default(10) we alter the size to 100 nodes
        double rc = default(0);//������ ���������, ���� ������ ������ � ������
        int startingNode;//������ ��� �� ��������� �� flooding
        @display("bgb=1000,1000;bgg=250");
    submodules:
        node[numNodes]: node;
    connections:
        for i=0..numNodes-1, for j=i+1..numNodes-1 {
            node[i].gate++ <--> {  delay = 1000ms; } <--> node[j].gate++ if i!=j && sqrt((node[i].xCor - node[j].xCor)^2+(node[i].yCor - node[j].yCor)^2)<rc;
        }
}

