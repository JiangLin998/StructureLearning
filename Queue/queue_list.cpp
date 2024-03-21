/**
  ******************************************************************************
  * @file           : queue_list.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */
#include <cstdlib>
#include <iostream>
#include "queue_list.h"

/**
 * @brief ����һ������
 * @return ����ָ��
 */
struct queue_list *queue_list_new(void) {
   struct queue_list *temp = (struct queue_list*)malloc(sizeof(struct queue_list));
   temp->write = temp->read = NULL;
   return temp;
}
/**
 * @brief ����push����
 * @param q ����ָ��
 * @param data Ҫ��ӵ�����
 */
void enqueue_list(struct queue_list *q, int data) {
    /* ����һ������ڵ� */
    struct list_node *temp = (struct list_node*)malloc(sizeof(struct list_node));
    if(temp) {
        temp->data = data;
        temp->next = NULL;
        /* �ж϶����Ƿ�Ϊ�� */
        if(q->read == NULL && q->write == NULL) {
            q->read = q->write = temp;
            return;
        }
        /* �������ӣ�����Ӳ��� */
        q->write->next = temp;
        q->write = temp;
    }
}
/**
 * @brief ����pop����
 * @param q ����ָ��
 */
void dequeue_list(struct queue_list *q) {
    struct list_node *temp = q->read;
    if(q->read == NULL) {
       std::cout << "��ȡʧ�ܣ�����Ϊ��\n";
       return;
    } else if(q->read == q->write) {
        /* �������ͷ�ˣ�����������Ϊ��ʼ״̬ */
       q->read = q->write = NULL;
       return;
    } else {
        q->read = q->read->next;
    }
    free(temp);
}
/**
 * @brief ��ӡ����������ֵ
 * @param q ����ָ��
 */
void queue_list_print(struct queue_list *q) {
    for(struct list_node *temp = q->read; temp != q->write->next; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}
/**
 * @brief ɾ������
 * @param q ����ָ��
 */
void queue_list_del(struct queue_list *q) {
    if(q) {
        free(q);
    }
}

