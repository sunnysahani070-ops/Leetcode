
class Solution(object):

  def reverseBetween(self, head, left, right):
    """:type head: Optional[ListNode]

    :type left: int
    :type right: int
    :rtype: Optional[ListNode]
    """
    if not head or left == right:
      return head
    # Dummy node to handle edge cases where left == 1
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy
    # Step 1: Reach node at position (left - 1)
    for _ in range(left - 1):
      prev = prev.next
    # Step 2: Reverse nodes between position left and right in-place
    curr = prev.next
    for _ in range(right - left):
      nxt = curr.next
      curr.next = nxt.next
      nxt.next = prev.next
      prev.next = nxt

    return dummy.next